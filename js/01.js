//求01交错串的最大长度

//input: 1111011
//output:3
// function test(line){
// 	function inverse(num){
//   	if(num=='1'){
//   		return '0'
//   	}else{
//   		return '1'
//   	}
//   }

// expected =inverse(line[0])
// 	var sum=1
// 	var max = 1
// 	for(var i =1;i<line.length;i++){
// 		if(line[i]==expected){
// 			console.log(i,line[i],expected)
// 			sum+=1
// 		}else{
// 			if(sum>max) max=sum
// 			sum=1
// 		}
// 		expected=inverse(line[i])
// 	}
// 	return max>sum?max:sum

// }



// console.log(test('0101010'))


// function test(arr){
// 	var flag = true
// 	var gap=0
// 	for(var i=0;i<arr.length-1;i++){
// 	    for(var j=0;j<arr.length-1-i;j++){
// 	        if(arr[j]>arr[j+1]){
// 	            var swap = arr[j]
// 	            arr[j]=arr[j+1]
// 	            arr[j+1]=swap
// 	        }
// 	    }
// 	    if(i>=1){
// 	        gap = parseInt(arr[arr.length-2])-parseInt(arr[arr.length-1])
// 	        if(parseInt(arr[arr.length-1-i])-parseInt(arr[arr.length-i])!=gap){
// 	        	console.log(gap,arr[arr.length-2],arr[arr.length-1],parseInt(arr[arr.length-1-i])-parseInt(arr[arr.length-i]),i)
// 	            flag=false
// 	            break
// 	        }
// 	    }

// 	}
// 	if(flag==true && (parseInt(arr[0])-parseInt(arr[1]))==gap){
//     console.log('Possible')
// }else{
//     console.log('Impossible')
// }
// }
// test([411, 306, 131, 96, 166, 446, 236, 516, 201, 481, 271, 61, 341, 376])]

for (var i = 0; i < 5; i++) {
	(function(i){
		setTimeout(function(){
			console.log(i)
		},1000)
	})(i)
}