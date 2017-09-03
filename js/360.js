function calu(arr) {
	var result = [0]
	for(var i=1;i<arr.length;i++){
		var count = 0
		for(var j=i-1;j>=0;j--){
			if(arr[i]<arr[j])
				count++
		}
		result[i]=count
	}
	return result
}

console.log(calu([4,5,1,3,2]))