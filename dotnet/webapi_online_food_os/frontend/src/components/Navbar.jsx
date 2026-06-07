import { Link, useNavigate } from "react-router-dom";
import {
    Button,
    Dropdown,
    Image,
    Badge,
    Container,
    Navbar as BsNavbar,
    Nav
} from "react-bootstrap";
import { useSelector, useDispatch } from "react-redux";
import { useMemo, useState } from "react";
import axios from "axios";
import { Constaint } from "../utils/Constaint";
import { toast } from "react-toastify";
import { setUser } from "../redux/reducers/UserSlice";

export default function Navbar() {
    const navigate = useNavigate();
    const user = useSelector(state => state.User.user);
    const cartItems = useSelector(state => state.Cart.cart);

    const dispatch = useDispatch();

    const countQty = useMemo(() => {
        return cartItems.reduce((prev, item) => prev + item.quantity, 0);
    }, [cartItems]);

    const handleLogout = async () => {

        try{

            const response = await axios.get(Constaint.BASE_URL + '/api/user/logout', { withCredentials: true });
            const { status, data, error } = response.data;
        }catch(err){
            toast.error(err);
        }finally{
            dispatch(setUser(null));
            toast.success(data);
            navigate('/');
        }
        
    };

    return (
        <BsNavbar
            bg="white"
            expand="lg"
            className="shadow-sm border-bottom sticky-top py-3"
        >
            <Container>

                {/* Logo */}
                <Link
                    to="/"
                    className="text-decoration-none d-flex align-items-center gap-2"
                >
                    <div
                        className="bg-danger text-white rounded-circle d-flex align-items-center justify-content-center"
                        style={{
                            width: "45px",
                            height: "45px",
                            fontSize: "20px"
                        }}
                    >
                        🍔
                    </div>

                    <div>
                        <h4 className="mb-0 fw-bold text-dark">
                            FoodOn
                        </h4>
                        <small className="text-muted">
                            Fast Delivery
                        </small>
                    </div>
                </Link>

                <BsNavbar.Toggle />

                <BsNavbar.Collapse>

                    {/* Center Links */}
                    <Nav className="mx-auto gap-lg-4">

                        <Link
                            to="/"
                            className="text-decoration-none text-dark fw-semibold"
                        >
                            Home
                        </Link>

                        <Link
                            to="/about"
                            className="text-decoration-none text-dark fw-semibold"
                        >
                            About
                        </Link>

                    </Nav>

                    {/* Right Side */}
                    <div className="d-flex align-items-center gap-3">

                        {user && (
                            <Link to="/cart">
                                <Button
                                    variant="outline-danger"
                                    className="position-relative"
                                >
                                    🛒 Cart

                                    {countQty > 0 && (
                                        <Badge
                                            bg="danger"
                                            pill
                                            className="position-absolute top-0 start-100 translate-middle"
                                        >
                                            {countQty}
                                        </Badge>
                                    )}
                                </Button>
                            </Link>
                        )}

                        {user ? (
                            <Dropdown align="end">

                                <Dropdown.Toggle
                                    variant="light"
                                    className="border d-flex align-items-center gap-2"
                                >
                                    <Image
                                        src={
                                            user?.avatar ||
                                            "https://i.pravatar.cc/100"
                                        }
                                        roundedCircle
                                        width={38}
                                        height={38}
                                    />

                                    <div className="text-start">
                                        <div
                                            style={{
                                                fontSize: "14px",
                                                fontWeight: "600"
                                            }}
                                        >
                                            {user?.name || "Akram Khan"}
                                        </div>

                                        <small className="text-muted">
                                            Customer
                                        </small>
                                    </div>
                                </Dropdown.Toggle>

                                <Dropdown.Menu>

                                    <Dropdown.Item as={Link} to="/orders">
                                        📦 My Orders
                                    </Dropdown.Item>

                                    <Dropdown.Divider />

                                    <Dropdown.Item
                                        onClick={handleLogout}
                                        className="text-danger"
                                    >
                                        🚪 Logout
                                    </Dropdown.Item>

                                    <Dropdown.Divider />

                                    <Dropdown.Item as={Link} to="/create-food">
                                        💀 Admin: Create Food
                                    </Dropdown.Item>
                                    <Dropdown.Item as={Link} to="/admin-foods">
                                        💀 Admin: Manage Foods
                                    </Dropdown.Item>


                                </Dropdown.Menu>

                            </Dropdown>
                        ) : (
                            <div className="d-flex gap-2">

                                <Link to="/login">
                                    <Button variant="outline-dark">
                                        Login
                                    </Button>
                                </Link>

                                <Link to="/signup">
                                    <Button variant="danger">
                                        Sign Up
                                    </Button>
                                </Link>

                            </div>
                        )}

                    </div>

                </BsNavbar.Collapse>

            </Container>
        </BsNavbar>
    );
}