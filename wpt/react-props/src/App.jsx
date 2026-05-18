// App.jsx

import Parent from './Parent';

function App() {

  const name = "Akram";

  return (
    <div>
      <h1>Props Drilling Example</h1>

      <Parent name={name} />
    </div>
  );
}

export default App;

// App.jsx with solve problem

import Parent from './Parent';
import UserContext from './UserContext';

function App() {

  const name = "Akram";

  return (

    <UserContext.Provider value={name}>

      <h1>Context API Example</h1>

      <Parent />

    </UserContext.Provider>

  );
}

export default App;