# Redux in React

# What is Redux?

Redux is a state management library.

It is used to manage global state in React applications.

Redux stores all application state in one central place called:

# Store

---

# Why Redux?

Without Redux:

```text
Component → Component → Component
```

Data passes using props.

This causes:

- Props drilling
- Difficult state management
- Complex code

Redux solves this problem.

---

# Core Concepts of Redux

Redux mainly has:

- Store
- Action
- Reducer
- Dispatch
- useSelector
- useDispatch

---

# Redux Flow

```text
Component
   ↓
Dispatch Action
   ↓
Reducer
   ↓
Store Updated
   ↓
UI Re-render
```

---

# 1. Store

Store contains all global state.

Example:

```js
{
  count: 0
}
```

---

# 2. Action

Action tells Redux:

"What should happen?"

Example:

```js
{
  type: "INCREMENT"
}
```

---

# 3. Reducer

Reducer updates state based on action.

Example:

```js
if(action.type === "INCREMENT"){
   return {
      count: state.count + 1
   }
}
```

---

# 4. Dispatch

Dispatch sends action to reducer.

Example:

```js
dispatch({
   type: "INCREMENT"
})
```

---

# 5. useSelector

Used to read data from store.

Example:

```js
const count = useSelector(state => state.count)
```

---

# 6. useDispatch

Used to send actions.

Example:

```js
const dispatch = useDispatch()
```

---

# Install Redux Toolkit

```bash
npm install @reduxjs/toolkit react-redux
```

---

# Project Structure

```text
src/
│
├── main.jsx
├── App.jsx
│
├── redux/
│   ├── store.js
│   └── counterSlice.js
```

---

# counterSlice.js

```jsx
import { createSlice } from '@reduxjs/toolkit';

const counterSlice = createSlice({

    name: 'counter',

    initialState: {
        count: 0
    },

    reducers: {

        increment: (state) => {
            state.count += 1;
        },

        decrement: (state) => {
            state.count -= 1;
        }

    }

});

export const { increment, decrement } = counterSlice.actions;

export default counterSlice.reducer;
```

---

# store.js

```jsx
import { configureStore } from '@reduxjs/toolkit';

import counterReducer from './counterSlice';

const store = configureStore({

    reducer: {
        counter: counterReducer
    }

});

export default store;
```

---

# main.jsx

```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

import App from './App';

import { Provider } from 'react-redux';

import store from './redux/store';

ReactDOM.createRoot(document.getElementById('root')).render(

    <Provider store={store}>

        <App />

    </Provider>

);
```

---

# App.jsx

```jsx
import { useSelector, useDispatch } from 'react-redux';

import { increment, decrement } from './redux/counterSlice';

function App() {

    const count = useSelector(state => state.counter.count);

    const dispatch = useDispatch();

    return (

        <div style={{ padding: '20px' }}>

            <h1>Redux Counter App</h1>

            <h2>Count : {count}</h2>

            <button onClick={() => dispatch(increment())}>
                Increment
            </button>

            <button onClick={() => dispatch(decrement())}>
                Decrement
            </button>

        </div>

    );
}

export default App;
```

---

# Output

```text
Count : 0

[Increment]
[Decrement]
```

---

# Difference Between Context API and Redux

| Context API | Redux |
|---|---|
| Built inside React | External library |
| Simple state management | Advanced state management |
| Good for small apps | Good for large apps |
| Less boilerplate | More structure |
| Performance can reduce in large apps | Better optimization |
| Easy to learn | Slightly difficult |
| No middleware | Supports middleware |

---

# When to Use Context API?

Use Context API when:

- Small applications
- Theme management
- User login data
- Language settings
- Simple global state

Example:

- Dark mode
- Logged-in user

---

# When to Use Redux?

Use Redux when:

- Large applications
- Complex state
- Many components
- API handling
- Large scale projects

Example:

- E-commerce websites
- Social media apps
- Dashboard applications

---

# Final Understanding

## Context API

Good for:

```text
Small + Simple Apps
```

---

## Redux

Good for:

```text
Large + Complex Apps
```