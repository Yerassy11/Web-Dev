const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');


function isP(number) {
    if (number < 2) return false;
    
    for (let i = 2; i <= Math.sqrt(number); i++) {
        if (number % i === 0) return false;
    }
    return true;
}

async function main() {
    const rl = readline.createInterface({ input, output });

    // Получаем данные от пользователя
    const answer = await rl.question('Введите число: ');
    const limit = Number(answer);

    let a = 2;
    let res = [];

    while (a < limit) {
        if (isP(a)) {
            res.push(a);
        }
        a++; 
    }

    console.log("Простые числа до", limit, ":", res);
    rl.close();
}

main();