import { useState } from "react";
import {
    Form,
    Button,
    Card,
    Container,
    Row,
    Col,
    Spinner
} from "react-bootstrap";
import { Link, useNavigate } from "react-router-dom";
import { toast } from "react-toastify";
import axios from "axios";
import { Constaint } from "../utils/Constaint";
import { useDispatch } from "react-redux";

export default function LoginPage() {
    const dispatch = useDispatch();
    const navigate = useNavigate();

    const [loading, setLoading] = useState(false);
    const [showPassword, setShowPassword] = useState(false);

    const [form, setForm] = useState({
        Email: "",
        Password: ""
    });

    const handleChange = (e) => {
        setForm({
            ...form,
            [e.target.name]: e.target.value
        });
    };

    const login = async (e) => {
        e.preventDefault();

        if (!form.Email.trim()) {
            return toast.error("Email is required");
        }

        if (!form.Password.trim()) {
            return toast.error("Password is required");
        }

        try {
            setLoading(true);

            axios.defaults.withCredentials = true;

            const res = await axios.post(
                 Constaint.BASE_URL + "/api/user/login",
                form,
                { withCredentials: true }
            );

            const { status, error, data } = res.data;

            if(status){
                toast.success("Welcome Back 👋");
                navigate('/');
                location.reload();
            }


        }
        catch (err) { 
            toast.error(err);
        }
        finally {
            setLoading(false);
        }
    };

    return (
        <Container fluid className="bg-light min-vh-100">

            <Row className="justify-content-center align-items-center min-vh-100">

                <Col md={5} lg={4}>

                    <Card className="border-0 shadow-lg rounded-4 overflow-hidden">

                        <div className="bg-danger text-white p-4 text-center">

                            <h2 className="fw-bold mb-2">
                                🍔 FoodOn
                            </h2>

                            <p className="mb-0">
                                Login to continue ordering food
                            </p>

                        </div>

                        <Card.Body className="p-4">

                            <h4 className="fw-bold mb-4 text-center">
                                Welcome Back
                            </h4>

                            <Form onSubmit={login}>

                                <Form.Group className="mb-3">
                                    <Form.Label>
                                        Email Address
                                    </Form.Label>

                                    <Form.Control
                                        size="lg"
                                        type="email"
                                        name="Email"
                                        placeholder="Enter email"
                                        value={form.Email}
                                        onChange={handleChange}
                                    />
                                </Form.Group>

                                <Form.Group className="mb-3">
                                    <Form.Label>
                                        Password
                                    </Form.Label>

                                    <div className="d-flex">

                                        <Form.Control
                                            size="lg"
                                            type={
                                                showPassword
                                                    ? "text"
                                                    : "password"
                                            }
                                            name="Password"
                                            placeholder="Enter password"
                                            value={form.Password}
                                            onChange={handleChange}
                                        />

                                        <Button
                                            variant="outline-secondary"
                                            type="button"
                                            onClick={() =>
                                                setShowPassword(
                                                    !showPassword
                                                )
                                            }
                                        >
                                            {showPassword ? "🙈" : "👁"}
                                        </Button>

                                    </div>
                                </Form.Group>

                                <div className="d-flex justify-content-between mb-4">

                                    <Form.Check
                                        type="checkbox"
                                        label="Remember Me"
                                    />

                                    <Link
                                        to="/forgot-password"
                                        className="text-decoration-none"
                                    >
                                        Forgot Password?
                                    </Link>

                                </div>

                                <Button
                                    type="submit"
                                    variant="danger"
                                    size="lg"
                                    className="w-100"
                                    disabled={loading}
                                >
                                    {loading ? (
                                        <>
                                            <Spinner
                                                size="sm"
                                                className="me-2"
                                            />
                                            Logging In...
                                        </>
                                    ) : (
                                        "Login"
                                    )}
                                </Button>

                            </Form>

                            <hr className="my-4" />

                            <div className="text-center">

                                Don't have an account?

                                <Link
                                    to="/signup"
                                    className="ms-2 fw-bold text-danger text-decoration-none"
                                >
                                    Create Account
                                </Link>

                            </div>

                        </Card.Body>

                    </Card>

                </Col>

            </Row>

        </Container>
    );
}