// Parent.jsx

import Child from './Child';

function Parent({ name }) {

  return (
    <div>
      <h2>Parent Component</h2>

      <Child name={name} />
    </div>
  );
}

export default Parent;