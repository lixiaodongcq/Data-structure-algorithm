var readline = require('readline')
var rl = readline.createInterface(process.stdin, process.stdout)

function convertTo26(inputString) {
	 if(inputString == null)
	 	return 'ERROR'
	 var n=0
	 for(var i=inputString.length-1,j=1;i>=0;i--,j*=26){
	 	var c = inputString[i]
	 	if(c<'a' || c>'z') return 'ERROR'
	 	n+=(c.charCodeAt()-96)*j
	 }
	 return n
}

function convertToString(n){
	var s=''
	while(n>0){
		var m = n%26
		if(m==0) m =26
		s=String.fromCharCode(m+96) + s
		n=(n-m)/26
	}
	return s
}

rl.on('line', function(line) {

	var inputString = line
	var result
	if (isNaN(parseInt(line))){
		result = convertTo26(inputString)
	}else{
		result = convertToString(parseInt(inputString))
	}

	console.log(result)

	rl.close()

})