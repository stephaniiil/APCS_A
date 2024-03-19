let correctButton = document.querySelector('button.correct');
let correctP = document.querySelector('p.display1');

correctButton.addEventListener('click', function() {
    correctButton.style.backgroundColor = 'green';
    correctP.textContent = "Correct!";
});

let incorrectButton = document.querySelectorAll('.incorrect');
let incorrectP = document.querySelector('p.display1');

for (let i = 0; i < incorrectButton.length; i++)
{
    incorrectButton[i].addEventListener('click', function() {
        incorrectButton[i].style.backgroundColor = 'red';
        incorrectP.textContent = "Incorrect";
    });
}

let correctText = document.querySelector('button.check');
let textP = document.querySelector('p.display2');
let input = document.querySelector('input[type="text"]');

correctText.addEventListener('click', function() {
    if (input.value == "Ruy Lopez") {
        textP.textContent = "Correct!";
    } else {
        textP.textContent = "Incorrect";
    }
})
