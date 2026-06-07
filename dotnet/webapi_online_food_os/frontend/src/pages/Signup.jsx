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

export default function SignupPage() {

    const navigate = useNavigate();

    const [loading, setLoading] = useState(false);
    const [showPassword, setShowPassword] = useState(false);

    const [form, setForm] = useState({
        Name: "",
        Email: "",
        Mobile: "",
        Password: "",
        ConfirmPassword: ""
    });

    const handleChange = (e) => {
        setForm({
            ...form,
            [e.target.name]: e.target.value
        });
    };

    const signup = async (e) => {
        e.preventDefault();

        if (!form.Name.trim())
            return toast.error("Name is required");

        if (!form.Email.trim())
            return toast.error("Email is required");

        if (!form.Mobile.trim())
            return toast.error("Mobile is required");

        if (!form.Password.trim())
            return toast.error("Password is required");

        if (form.Password.length < 6)
            return toast.error("Password must be at least 6 characters");

        if (form.Password !== form.ConfirmPassword)
            return toast.error("Passwords do not match");

        try {

            setLoading(true);

            await axios.post(
                Constaint.BASE_URL + "/api/user/signup",
                {
                    Name: form.Name,
                    Email: form.Email,
                    Mobile: form.Mobile,
                    Password: form.Password
                }
            );

            toast.success("Account Created Successfully 🎉");

            navigate("/login");

        } catch (err) {

            toast.error(
                err.response?.data?.message ||
                "Signup Failed"
            );

        } finally {
            setLoading(false);
        }
    };

    return (
        <Container fluid className="bg-light min-vh-100">

            <Row className="justify-content-center align-items-center min-vh-100">

                <Col md={6} lg={5}>

                    <Card className="border-0 shadow-lg rounded-4 overflow-hidden">

                        <div className="bg-danger text-white text-center p-4">

                            <h2 className="fw-bold">
                                🍔 FoodOn
                            </h2>

                            <p className="mb-0">
                                Create your account and start ordering
                            </p>

                        </div>

                        <Card.Body className="p-4">

                            <h3 className="fw-bold text-center mb-4">
                                Create Account
                            </h3>

                            <Form onSubmit={signup}>

                                <Form.Group className="mb-3">
                                    <Form.Label>Full Name</Form.Label>
                                    <Form.Control
                                        size="lg"
                                        name="Name"
                                        placeholder="Enter your name"
                                        value={form.Name}
                                        onChange={handleChange}
                                    />
                                </Form.Group>

                                <Form.Group className="mb-3">
                                    <Form.Label>Email</Form.Label>
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
                                    <Form.Label>Mobile Number</Form.Label>
                                    <Form.Control
                                        size="lg"
                                        name="Mobile"
                                        placeholder="Enter mobile number"
                                        value={form.Mobile}
                                        onChange={handleChange}
                                    />
                                </Form.Group>

                                <Form.Group className="mb-3">
                                    <Form.Label>Password</Form.Label>

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
                                            type="button"
                                            variant="outline-secondary"
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

                                <Form.Group className="mb-4">
                                    <Form.Label>
                                        Confirm Password
                                    </Form.Label>

                                    <Form.Control
                                        size="lg"
                                        type={
                                            showPassword
                                                ? "text"
                                                : "password"
                                        }
                                        name="ConfirmPassword"
                                        placeholder="Confirm password"
                                        value={form.ConfirmPassword}
                                        onChange={handleChange}
                                    />
                                </Form.Group>

                                <Button
                                    variant="danger"
                                    size="lg"
                                    className="w-100"
                                    type="submit"
                                    disabled={loading}
                                >
                                    {loading ? (
                                        <>
                                            <Spinner
                                                size="sm"
                                                className="me-2"
                                            />
                                            Creating Account...
                                        </>
                                    ) : (
                                        "Create Account"
                                    )}
                                </Button>

                            </Form>

                            <hr className="my-4" />

                            <div className="text-center">

                                Already have an account?

                                <Link
                                    to="/login"
                                    className="ms-2 text-danger fw-bold text-decoration-none"
                                >
                                    Login
                                </Link>

                            </div>

                        </Card.Body>

                    </Card>

                </Col>

            </Row>

        </Container>
    );
}