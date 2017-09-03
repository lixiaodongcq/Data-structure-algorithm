//1,冒泡排序
//稳定，时间复杂度为O(n^2),空间复杂度为O(1)

function bubbleSort(arr) {
	for (var i = 0; i < arr.length - 1; i++) {
		for (var j = 0; j < arr.length - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				var swap = arr[j]
				arr[j] = arr[j + 1]
				arr[j + 1] = swap
			}
		}
	}
	return arr
}

//2,冒泡排序
//不稳定，最好时间复杂度nlog(n),最坏n^2,空间复杂度log（n）

function quickSort(arr) {
	if (arr.length <= 1) {
		return arr
	}
	var poivtIndex = Math.floor(arr.length / 2)

	var poivt = arr.splice(poivtIndex, 1)[0]
	var left = []
	var right = []
	for (var i = 0; i < arr.length; i++) {
		if (arr[i] <= poivt) {
			left.push(arr[i])
		} else {
			right.push(arr[i])
		}
	}
	return quickSort(left).concat([poivt], quickSort(right))
}


//3. insert sort
// stable,time O(n^2),space O(1)

function insertSort(arr) {
	for (var i = 1; i < arr.length; i++) {
		var guard = arr[i]
		var j = i - 1
		while (j >= 0 && arr[j] > guard) {
			arr[j + 1] = arr[j]
			j--
		}
		arr[j + 1] = guard
	}
	return arr
}


//4, selectSort
//unstable time O(n^2) space O(1)

function selectSort(arr) {
	var minIndex, swap
	for (var i = 0; i < arr.length - 1; i++) {
		minIndex = i
		for (var j = i + 1; j < arr.length; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j
			}
		}
		swap = arr[i]
		arr[i] = arr[minIndex]
		arr[minIndex] = swap
	}
	return arr
}


//5,heapSort
// unstable time O(nlogn) space O(1)

function buildMaxHeap(arr) {
	for (var i = Math.floor(arr.length) / 2 - 1; i >= 0; i--) {
		heapAdjust(arr, i, arr.length)
	}
}

function heapAdjust(arr, i, len) {
	var maxIndex = i
	var left = maxIndex * 2 + 1
	var right = maxIndex * 2 + 2
	if (left < len && arr[maxIndex] < arr[left]) {
		maxIndex = left
	}
	if (right < len && arr[maxIndex] < arr[right]) {
		maxIndex = right
	}

	if (maxIndex != i) {
		swap(arr, i, maxIndex)
		heapAdjust(arr, maxIndex, len)
	}
}

function swap(arr, i, j) {
	var tmp = arr[i]
	arr[i] = arr[j]
	arr[j] = tmp
}


function heapSort(arr) {
	buildMaxHeap(arr)
	console.log('buildMaxHeap:' + arr)
	for (var i = arr.length - 1; i > 0; i--) {
		swap(arr, 0, i)
		heapAdjust(arr, 0, i)
	}
	return arr
}



a = [2, 3, 89, 57, 23, 72, 43, 105]
heapSort(a)
console.log('heapSort:' + a);



(function testSort() {
	var arr = [10, 5, 2, 3, 9, 6, 1, 8, 7]
	console.log('before Sort:' + arr)
		//arr = bubbleSort(arr)
		//arr = quickSort(arr)
		//arr=insertSort(arr)
	arr = selectSort(arr)
	console.log('after Sort:' + arr)
})()