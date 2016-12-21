var fs = require('fs');
var path = require('path');

module.exports = function(dirName, ext, callback){	
		fs.readdir(dirName, function(error,list){
		if (error) return callback(error,null)
		else {
		fileList = []
		getFiles(dirName, fileList);
		for (i in fileList) {
		    if (path.extname(fileList[i]) == ext){
		    fileList.push(fileList[i])
			console.log('push',fileList[i]);
		    }
	}
	callback(null, fileList);
		}
  	})
}

function getFiles(dir, fileList){
	var files = fs.readdirSync(dir);
	for (var i in files)
	{
		if (!files.hasOwnProperty(i)) continue;
		var name = dir+'/'+files[i];
		if (fs.statSync(name).isDirectory()){
			getFiles(name, fileList);
		} else {
			fileList.push(name);
		}
	}
	return fileList;
}
