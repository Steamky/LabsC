Balance = prompt("Введите свой бюджет:");
const mobile_cost = 199.99;
const accesor_cost = 49.99;
const TAX_RATE = 0.2
buy_score = 0;
function all_cost(){
    global_cost = (mobile_cost + accesor_cost) * (1 + TAX_RATE);
    alert(global_cost.toFixed(2)+"₽", );
    return global_cost;
} 
all_cost();
while (Balance >= global_cost) {
    Balance = Balance - global_cost;
    buy_score+=1;
}
console.log(buy_score);