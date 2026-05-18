import {
    BrowserRouter,
    Routes,
    Route,
    Link
} from 'react-router-dom';

import Home from './pages/Home';
import About from './pages/About';
import Contact from './pages/Contact';
import User from './pages/User';

function App() {

    return (

        <BrowserRouter>

            <div style={{ padding: '20px' }}>

                <h1>React Router Example</h1>

                {/* Static Navigation */}

                <nav>

                    <Link to="/">Home</Link>

                    {' | '}

                    <Link to="/about">About</Link>

                    {' | '}

                    <Link to="/contact">Contact</Link>

                    {' | '}

                    {/* Dynamic Navigation */}

                    <Link to="/user/101">User 101</Link>

                    {' | '}

                    <Link to="/user/102">User 102</Link>

                </nav>

                <hr />

                <Routes>

                    {/* Static Routes */}

                    <Route path="/" element={<Home />} />

                    <Route path="/about" element={<About />} />

                    <Route path="/contact" element={<Contact />} />

                    {/* Dynamic Route */}

                    <Route path="/user/:id" element={<User />} />

                </Routes>

            </div>

        </BrowserRouter>

    );
}

export default App;