
const taskInput = document.getElementById('task-input');
const addBtn = document.getElementById('add-btn');
const todoList = document.getElementById('todo-list');

function addTask() {
    const taskValue = taskInput.value;

    if (taskValue.trim() === "") {
        alert("Пожалуйста, введите текст задачи!");
        return;
    }

    
    const li = document.createElement('li');

    const checkbox = document.createElement('input');
    checkbox.type = 'checkbox';
    
    
    checkbox.addEventListener('change', function() {
        if (checkbox.checked) {
            span.classList.add('completed'); 
        } else {
            span.classList.remove('completed'); 
        }
    });

    const span = document.createElement('span');
    span.textContent = taskValue;
    span.classList.add('task-text');

    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = 'Удалить';
    deleteBtn.classList.add('delete-btn');

    deleteBtn.addEventListener('click', function() {
        todoList.removeChild(li);
    });

    
    li.appendChild(checkbox);
    li.appendChild(span);
    li.appendChild(deleteBtn);

    
    todoList.appendChild(li);

    taskInput.value = "";
}

addBtn.addEventListener('click', addTask);

taskInput.addEventListener('keypress', function(e) {
    if (e.key === 'Enter') {
        addTask();
    }
});