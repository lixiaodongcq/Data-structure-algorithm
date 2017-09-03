class Cash {
	constructor(money) {
		this.money = money
	}
	static add(cash1, cash2) {
		return new Cash(cash1.money + cash2.money)
	}
	add(cash) {
		return new Cash(this.money + cash.money)
	}
	valueOf() {
		return this.money
	}
	toString() {
		let yuan = Math.floor(this.money / 100)
		let jiao = Math.floor((this.money - yuan * 100) / 10)
		let fen = (this.money - yuan * 100 - jiao * 10)
		return yuan + "元" + jiao + "角" + fen + "分"
	}
}

const cash1 = new Cash(105);
const cash2 = new Cash(66)

const cash3 = cash1.add(cash2)
const cash4 = Cash.add(cash1, cash2)
const cash5 = new Cash(cash1 + cash2)

console.log(`${cash3}`, `${cash4}`, `${cash5}`) // 1元7角1分,1元7角1分,1元7角1分	



