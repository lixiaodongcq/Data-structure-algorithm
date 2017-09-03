//闭包以及暴露接口---学习笔记
var obj = (function() {
	var value = 0
	return {
		getValue: function() {
			return value
		},
		setValue: function(v) {
			if (typeof v === 'number') {
				value = v
			}
		}
	}

})()

//这个value变量我们叫私有变量，这两个可以访问私有变量的共有方法就叫做特权方法。

obj.setValue(10)
var a = obj.getValue()

console.log(a)

/*
//构造一个函数，本义是通过内部函数返回一个函数数组，数组中每一项都是一个函数
//数组项函数会返回当前的数组索引
//但是最后每一项的函数都会得到返回10

*/

var eg1 = function(){
	var i,result = []
	for(var i=0;i<10;i++){
		
	}
}

var eg2 = function() {
	var i, result = []
	for (var i = 0; i < 10; i++) {
		(function(i) {
			result[i] = function() {
				return i;
			}
		})(i)

	}
	return result
}

var result = eg2()

result.map(e => console.log(e()))