var readline = require('readline')
var rl = readline.createInterface(process.stdin, process.stdout)
var inputArr = []
var counter = 0
var clicknum = 0
var first = true
var clickCount = 0

rl.on('line', function(line) {
	inputArr.push(line)
	if (!isNaN(parseInt(line))) {
		counter++
	}
	if (counter == 2) {
		if (first) {
			clicknum = parseInt(line)
			first = false
		}
		clickCount++
		if (clicknum + 1 == clickCount) {
			var total = parseInt(inputArr[0])
			var totalArr = inputArr.slice(1, total+1)
			var click = parseInt(inputArr[totalArr.length+1])
			var clickArr = inputArr.slice(totalArr.length+2)
			var uniq = Array.from(new Set(clickArr))
			var res = totalArr.filter(e=>uniq.indexOf(e)==-1)
			res.sort()
			res.forEach(e=>console.log(e))
			rl.close()
			
		}
	}
})