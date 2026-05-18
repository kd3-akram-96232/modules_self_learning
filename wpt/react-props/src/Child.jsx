// Child.jsx

import GrandChild from './GrandChild';

function Child({ name }) {

  return (
    <div>
      <h3>Child Component</h3>

      <GrandChild name={name} />
    </div>
  );
}

export default Child;