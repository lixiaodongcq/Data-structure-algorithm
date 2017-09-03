var readline = require('readline')
var rl = readline.createInterface(process.stdin, process.stdout)

function xiaochu(inputString) {
	var array = inputString.split("")
	var set = new Set()
	for (var i of array) {
		set.add(i)
	}

	if (array.length == set.size) {
		return inputString
	}
	for (let i = 0; i < inputString.length; i++) {
		for (let j = i + 1; j < inputString.length; j++) {
			if (inputString.charAt(i) == inputString.charAt(j)) {
				var arrayA = inputString.split("")
				arrayA[i] = ""
				var a = arrayA.join("")
				var arrayB = inputString.split("")
				arrayB[j] = ""
				var b = arrayB.join("")
				if (a > b) {
					return xiaochu(a)
				} else {
					return xiaochu(b)
				}
			}
		}
	}
}

rl.on('line', function(line) {

	var inputString = line

	var a = xiaochu(inputString)

	console.log(a)

	rl.close()

})