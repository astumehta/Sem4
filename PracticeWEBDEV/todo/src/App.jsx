import React, { useState } from 'react';

function TodoList() {
  const [todos, setTodos] = useState([]);
  const [newTodo, setNewTodo] = useState('');
  const addTodo = () => {
    if (newTodo.trim() !== '') {
      setTodos([...todos, { id: Date.now(), text: newTodo, completed: false }]);
      setNewTodo('');
    }
  };
  const removeTodo = (id) => setTodos(todos.filter((todo) => todo.id !== id));

  return (
    <div>
      <input type="text"  value={newTodo}  onChange={(e) => setNewTodo(e.target.value)}  onKeyPress={(e) => { if (e.key === 'Enter') addTodo(); }}/>
      <ul>
        {todos.map((todo) => (
          <li key={todo.id}>
            <span>{todo.text}</span>
            <button onClick={() => removeTodo(todo.id)}>Remove</button>
          </li>
        ))}
      </ul>
      {todos.length === 0 && <p>No tasks yet!</p>}
    </div>
  );
}

export default TodoList;
