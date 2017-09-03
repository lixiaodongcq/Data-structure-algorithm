
var arr = [[-2,-3,3],[-5,-10,1]]

function main(arr){
	var row = 0
	var col = 0
	var sum = 0
	while(row<arr.length && col<arr[0].length){
		var down = arr[row][col] + arr[row][col+1]
		var left = arr[row+1][col] + arr[row][col]
		var min = down>left?left:down
		if(min<0){
			sum+=min
		}

	}	
}