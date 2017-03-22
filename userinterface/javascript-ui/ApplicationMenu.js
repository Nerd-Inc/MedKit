const electron = require('electron');

let MENU_TEMPLATE = [
	{
		label: 'File',
		submenu: [{ label: 'Exit', accelerator: 'CmdOrCtrl+Q', role: 'quit' }]
	},
	{
		label: 'Edit',
		submenu: [
			{ label: 'Undo', accelerator: 'CmdOrCtrl+Z', role: 'undo' },
			{ label: 'Redo', accelerator: 'Shift+CmdOrCtrl+Z', role: 'redo' },
			{ type: 'separator' },
			{ label: 'Cut', accelerator: 'CmdOrCtrl+X', role: 'cut' },
			{ label: 'Copy', accelerator: 'CmdOrCtrl+C', role: 'copy' },
			{ label: 'Paste', accelerator: 'CmdOrCtrl+V', role: 'paste' },
			{ label: 'Select All', accelerator: 'CmdOrCtrl+A', role: 'selectall' }
		]
	},
	{
		label: 'View',
		submenu: [{
			label: 'Toggle Full Screen',
			accelerator: 'F11',
			click: function (item, focusedWindow) {
				if (focusedWindow) focusedWindow.setFullScreen(!focusedWindow.isFullScreen());
			}
		}]
	}, {
		label: 'Help',
		role: 'help',
		submenu: [{
			label: 'About MedKit',
			click: function (item, focusedWindow) {
				const version = electron.app.getVersion()
				if (focusedWindow) {
					const options = {
						type: 'info',
						title: 'MedKit',
						buttons: ['Ok'],
						message: 'Name: MedKit \nDescription: Offline First Symptoms Search Engine\nVersion: ' + version + '\nDevelopers: \n Wisdom Nji\n Collin Grimm\n Chick Joel'
					}
					electron.dialog.showMessageBox(focusedWindow, options, function () { })
				}
			}
		}]
	}]
module.exports = MENU_TEMPLATE;
