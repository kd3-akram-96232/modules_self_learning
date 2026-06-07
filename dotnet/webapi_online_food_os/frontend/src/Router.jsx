import { BrowserRouter, Routes, Route } from 'react-router-dom';
import AuthLayout from './layouts/AuthLayout';
import SignupPage from './pages/Signup';
import LoginPage from './pages/Login';
import ProtectedRoute from './layouts/ProtectedRoute';
import HomePage from './pages/Home';
import CartPage from './pages/Cart';
import AboutPage from './pages/About';
import MainLayout from './layouts/MainLayout';
import { useEffect } from 'react';
import { Constaint } from './utils/Constaint';
import axios from 'axios';
import { useDispatch } from 'react-redux';
import { setUser } from './redux/reducers/UserSlice';
import { toast } from 'react-toastify';
import OrdersPage from './pages/Orders';
import CheckoutPage from './pages/Checkout';
import CreateFoodPage from './pages/CreateFoodPage';
import AdminFoodsPage from './pages/AdminFoodsPage';

export default function Router() {
    const dispatch = useDispatch();

    const getLoggedInUser = async () => {

        const response = await axios.get(Constaint.BASE_URL + '/api/user/me', {withCredentials: true});

        const { status, error, data } = response.data;

        if (status) {
            dispatch(setUser(data));
        } else {
            toast.error(error);
        }

    };

    useEffect(() => { getLoggedInUser() }, [])

    return (
        <BrowserRouter>
            <Routes>
                <Route element={<AuthLayout />}>
                    <Route path='/login' element={<LoginPage />} />
                    <Route path='/signup' element={<SignupPage />} />
                </Route>

                <Route element={<MainLayout />}>

                    <Route path='/' element={<HomePage />} />
                    <Route path='/about' element={<AboutPage />} />

                    <Route element={<ProtectedRoute />}>
                        <Route path='/cart' element={<CartPage />} />
                        <Route path='/profile' element={<CartPage />} />
                        <Route path='/orders' element={<OrdersPage />} />
                        <Route path='/checkout' element={<CheckoutPage />} />

                        <Route path='/create-food' element={<CreateFoodPage />} />
                        <Route path='/admin-foods' element={<AdminFoodsPage />} />
                    </Route>

                </Route>

            </Routes>
        </BrowserRouter>
    )

}