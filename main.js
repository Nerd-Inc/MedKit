const electron = require('electron');
const path = require('path');
const appMenuTemplate = require('./userinterface/javascript-ui/ApplicationMenu');

const ipcMain = electron.ipcMain;
const electronMenu = electron.Menu
const app = electron.app;
const BrowserWindow = electron.BrowserWindow;

let mainWindow;

var MEDKIT_HOME = path.join('file://', __dirname, 'userinterface/pages/index.html');
var destroyWindow = () => { mainWindow = null; }
var activateWindowDarwin = () => { if (mainWindow = null) createWindow; }
var closeAllWindow = () => { if (process.platform !== 'darwin') app.quit(); }
var createAplicationMenu = function (){
	const menu = electronMenu.buildFromTemplate(appMenuTemplate)
	electronMenu.setApplicationMenu(menu)
}

var createWindow = function () {
	mainWindow = new BrowserWindow({
		width: 1024,
		height: 600,
		backgroundColor: '#673AB7',
		title: 'MedKit - Symptoms Search Engine',
		titleBarStyle: 'hidden'
	});
	mainWindow.loadURL(MEDKIT_HOME);
	mainWindow.on('closed', destroyWindow);
};

app.on('ready', createWindow);
app.on('ready', createAplicationMenu);
app.on('window-all-closed', closeAllWindow);
