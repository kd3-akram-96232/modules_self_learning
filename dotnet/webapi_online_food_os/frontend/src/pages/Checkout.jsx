import axios from "axios";
import {
    Container,
    Card,
    Row,
    Col,
    Button,
    Form
} from "react-bootstrap";
import { useSelector, useDispatch } from "react-redux";
import { clearCart } from "../redux/reducers/CartSlice";
import { toast } from "react-toastify";
import { useNavigate } from "react-router-dom";
import { Constaint } from "../utils/Constaint";
import { useState } from "react";

export default function CheckoutPage() {

    const cartItems = useSelector(
        state => state.Cart.cart
    );

    const dispatch = useDispatch();
    const navigate = useNavigate();

    const [loading, setLoading] =
        useState(false);

    const total = cartItems.reduce(
        (sum, item) =>
            sum + item.price * item.quantity,
        0
    );

    const deliveryFee = 40;

    const placeOrder = async () => {

        try {

            setLoading(true);

            const payload = {
                TotalAmount:
                    total + deliveryFee,

                CartItems:
                    cartItems.map(item => ({
                        Fid: item.fid,
                        Qty: item.quantity
                    }))
            };            

            const response =
                await axios.post(
                    `${Constaint.BASE_URL}/api/Orders`,
                    payload,
                    {
                      withCredentials: true
                    }
                );

            const {
                status,
                error
            } = response.data;

            if (!status) {
                return toast.error(error);
            }

            dispatch(clearCart());

            toast.success(
                "Order placed successfully 🎉"
            );

            navigate("/orders");

        } catch (err) {

            toast.error(
                err.response?.data?.error ||
                "Failed to place order"
            );

        } finally {

            setLoading(false);

        }
    };

    return (
        <Container className="py-4">

            <h2 className="mb-4">
                Checkout
            </h2>

            <Row>

                <Col lg={8}>

                    <Card className="border-0 shadow-sm">

                        <Card.Body>

                            <h4 className="mb-4">
                                Delivery Information
                            </h4>

                            <Form>

                                <Form.Group className="mb-3">
                                    <Form.Label>
                                        Full Name
                                    </Form.Label>

                                    <Form.Control
                                        placeholder="Enter your name"
                                    />
                                </Form.Group>

                                <Form.Group className="mb-3">
                                    <Form.Label>
                                        Mobile Number
                                    </Form.Label>

                                    <Form.Control
                                        placeholder="Enter mobile"
                                    />
                                </Form.Group>

                                <Form.Group className="mb-3">
                                    <Form.Label>
                                        Delivery Address
                                    </Form.Label>

                                    <Form.Control
                                        as="textarea"
                                        rows={4}
                                    />
                                </Form.Group>

                            </Form>

                        </Card.Body>

                    </Card>

                </Col>

                <Col lg={4}>

                    <Card className="border-0 shadow-sm">

                        <Card.Body>

                            <h4>
                                Order Summary
                            </h4>

                            <hr />

                            {cartItems.map(item => (

                                <div
                                    key={item.fid}
                                    className="d-flex justify-content-between mb-2"
                                >

                                    <span>
                                        {item.name}
                                        {" "}
                                        x
                                        {item.quantity}
                                    </span>

                                    <span>
                                        ₹
                                        {
                                            item.price *
                                            item.quantity
                                        }
                                    </span>

                                </div>

                            ))}

                            <hr />

                            <div className="d-flex justify-content-between">

                                <span>
                                    Food Total
                                </span>

                                <span>
                                    ₹{total}
                                </span>

                            </div>

                            <div className="d-flex justify-content-between">

                                <span>
                                    Delivery Fee
                                </span>

                                <span>
                                    ₹40
                                </span>

                            </div>

                            <hr />

                            <div className="d-flex justify-content-between fw-bold">

                                <span>
                                    Grand Total
                                </span>

                                <span>
                                    ₹
                                    {
                                        total +
                                        deliveryFee
                                    }
                                </span>

                            </div>

                            <Button
                                className="w-100 mt-4"
                                variant="success"
                                onClick={placeOrder}
                                disabled={loading}
                            >
                                {
                                    loading
                                        ? "Placing Order..."
                                        : "Place Order"
                                }
                            </Button>

                        </Card.Body>

                    </Card>

                </Col>

            </Row>

        </Container>
    );
}