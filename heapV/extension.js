// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require('vscode');

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed

/**
 * @param {vscode.ExtensionContext} context
 */
var punt;
function activate(context) {
	context.subscriptions.push(
		vscode.commands.registerCommand('heapV.mostrar', () => {
		  // Crea el panel de webview
		  const panel = vscode.window.createWebviewPanel(
			'HeapVisualizer',
			'Heap Visualizer',
			vscode.ViewColumn.One,
			{enableScripts: true}
		  );
		  
			// Está constantemente actualizando el web view
      		const updateWebview = () => {
				actualizar();
				panel.webview.html = getWebviewContent(punt);
			  	}
			panel.webview.onDidReceiveMessage(
				message => {
				  switch (message.command) {
					case 'alert':
					  vscode.window.showErrorMessage(message.text);
					  return;
				  }
				},
				undefined,
        		context.subscriptions
				);
			updateWebview();
		 // intervalo de la actualizacion cada 5 segundos.
			const interval = setInterval(updateWebview, 5000);
		 //Limpia el intervalo cuando se cierra la web view
		  panel.onDidDispose(
			  ()=>{
				  clearInterval(interval);
			  },null,
			  context.subscriptions
		  )
		})

	  );
}
exports.activate = activate;
//actualiza los datos de la tabla, el socket envia los punteros.
function actualizar(punteros){
	punt =  `<tr>
		<td> gola</td>
	</tr>`;
}
// retorna la estructura del html
function getWebviewContent(puntero) {
	return ` <!DOCTYPE html>
	<html>
	<head>
		<meta charset="UTF-8">
		<title>
			Heap Visualizer
		</title>
	</head>
	<style type="text/css">
		body{
			background-color: #e0e0e0;
			font-family: monospace;
			font-size: 20px;
		}
		table, th, td{
			border: 4px solid teal;
			border-collapse: collapse;
			margin:-500px 600px ;
		}
		td{
			background-color: wheat;
		}
		th{
			background-color: lightgray;
			color: black;
		}
		h1{
			width: 100%;
			height: 50px;
			position: relative;
			color: white;
			background-color: teal;
			top:-20px;
		}
		form{
			background: rgba(0,0,0,0.4);
			width: 480px;
			padding: 10px 20px;
			border-radius: 7px;
			
		}
		h2{
			background-color: #43a047;
			border-radius: 7px;
			margin-top: 5px;
			color: white;
			
		}
		input{
			width: 100%;
			margin-bottom: 20px;
			padding: 7px;
			box-sizing: border-box;
		}
		#boton{
			background-color:#4caf50;
			border-color: #4caf50;
			color: white;
			padding: 7px;
		}
		#boton:hover{
			cursor: pointer;
		}
	</style>
	<body>
		<h1>Heap Visualizer</h1>
		<form>
			<h2>
				Establecer Conexión con el Servidor
			</h2>
			<label for="1">Coloque un usuario</label>
			<input type="text" name: "user" placeholder="Usuario" id="1">
			<label for="2">Escriba una contraseña</label>
			<input type="password" name "Contraseña" placeholder="Contraseña" id="2">
			<label for="3">Introduzca el puerto a conectarse</label>
			<input type="text" name"Puerto" placeholder="Puerto" id="3">
			<label for="4">Ip del servidor</label>
			<input type="text" name"ip" placeholder="ip" id="4">
			<input type="button" name "aceptar" value="Probar conexión" id="boton">
	
		</form>
		<table style="width: 50%;">
			<tr>
				<th>Tipo</th>
				<th>Direcciòn de memoria</th>
				<th>Valor Almacenado</th>
				<th>Referencias</th>
			</tr>
			"${puntero}"
		</table>
		<script>
        window.onload = function(){
            document.getElementById("boton").onclick=getDatos;
        }
        function getDatos(){
			const vscode = acquireVsCodeApi();
            var datos = "";
            var ids =["1","2","3","4"];
            for(var i=0;i<4;i++){ 
                datos += document.getElementById(ids[i]).value + ",";
            }
            vscode.postMessage({
				command: 'alert',
				text: datos
			})
        }
    </script>
	</body>
	</html>`;
  
}

// this method is called when your extension is deactivated
function deactivate() {}

module.exports = {
	activate,
	deactivate
}
