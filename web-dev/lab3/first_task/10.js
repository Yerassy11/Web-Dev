const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

async function askNumber() {
    const rl = readline.createInterface({ input, output });
    let num;

    while (true) {
        const answer = await rl.question('Введите число больше 100: ');
        num = Number(answer);

        if (num > 100) {
            console.log(`Отлично! Число ${num} подходит.`);
            break;
        }
        console.log("Маловато, попробуйте еще раз.");
    }

    rl.close();
}

askNumber();