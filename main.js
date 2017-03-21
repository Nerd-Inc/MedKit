const electron = require('electron');
const path = require('path');
const ipcMain = require('electron').ipcMain;

const app = electron.app;
const BrowserWindow = electron.BrowserWindow;

let mainWindow;

var medkitHome = path.join('file://', __dirname, 'userinterface/pages/index.html');
var destroyWindow = () => { mainWindow = null; }
var activateWindowDarwin = () => { if (mainWindow = null) createWindow; }
var closeAllWindow = () => { if (process.platform !== 'darwin') app.quit(); }

var createWindow = function () {
	mainWindow = new BrowserWindow({
		width: 1024,
		height: 600,
		backgroundColor: '#673AB7',
		title: 'MedKit - Symptoms Search Engine',
		titleBarStyle: 'hidden'
	});
	mainWindow.loadURL(medkitHome);
	mainWindow.on('closed', destroyWindow);
};

app.on('ready', createWindow);
app.on('window-all-closed', closeAllWindow);
