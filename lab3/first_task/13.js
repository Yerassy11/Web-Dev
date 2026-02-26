function checkAge(age) {
  return (age > 18) ? true : confirm('Did parents allow you?');
}



function compare(a,b){
    if (a<b){
        min=a;
    }
    else{
        min=b;
    }
    return min;
}


function pow(x, n) {
  let result = x;

  for (let i = 1; i < n; i++) {
    result *= x;
  }

  return result;
}

let x = prompt("x?", '');
let n = prompt("n?", '');

if (n < 1) {
  alert(`Power ${n} is not supported, use a positive integer`);
} else {
  alert( pow(x, n) );
}