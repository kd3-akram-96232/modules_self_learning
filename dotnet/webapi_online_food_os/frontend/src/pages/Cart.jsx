import {
    Container,
    Table,
    Button,
    Card,
    Row,
    Col
} from "react-bootstrap";
import { useDispatch, useSelector } from "react-redux";
import {
    decreamentQuantity,
    incrementQuantity,
    removeFromCart
} from "../redux/reducers/CartSlice";
import { useNavigate } from "react-router-dom";

export default function CartPage() {

    const cartItems = useSelector(
        state => state.Cart.cart
    );

    const dispatch = useDispatch();
    const navigate = useNavigate();

    const total = cartItems.reduce(
        (sum, item) =>
            sum + item.price * item.quantity,
        0
    );

    return (
        <Container className="py-4">

            <h2 className="mb-4">
                🛒 Shopping Cart
            </h2>

            <Row>

                <Col lg={8}>

                    <Card className="shadow-sm border-0">

                        <Card.Body>

                            <Table responsive hover>

                                <thead>
                                    <tr>
                                        <th>Food</th>
                                        <th>Name</th>
                                        <th>Price</th>
                                        <th>Qty</th>
                                        <th>Total</th>
                                        <th></th>
                                    </tr>
                                </thead>

                                <tbody>

                                    {cartItems.map(item => (

                                        <tr key={item.fid}>

                                            <td>
                                                <img
                                                    src={item.image}
                                                    alt={item.name}
                                                    width="80"
                                                    height="80"
                                                    className="rounded"
                                                />
                                            </td>

                                            <td>
                                                {item.name}
                                            </td>

                                            <td>
                                                ₹{item.price}
                                            </td>

                                            <td>

                                                <div className="d-flex align-items-center gap-2">

                                                    <Button
                                                        size="sm"
                                                        variant="outline-danger"
                                                        onClick={() =>
                                                            dispatch(
                                                                decreamentQuantity(item)
                                                            )
                                                        }
                                                    >
                                                        -
                                                    </Button>

                                                    <span>
                                                        {item.quantity}
                                                    </span>

                                                    <Button
                                                        size="sm"
                                                        variant="outline-success"
                                                        onClick={() =>
                                                            dispatch(
                                                                incrementQuantity(item)
                                                            )
                                                        }
                                                    >
                                                        +
                                                    </Button>

                                                </div>

                                            </td>

                                            <td>
                                                ₹
                                                {
                                                    item.price *
                                                    item.quantity
                                                }
                                            </td>

                                            <td>

                                                <Button
                                                    size="sm"
                                                    variant="outline-danger"
                                                    onClick={() =>
                                                        dispatch(
                                                            removeFromCart(item)
                                                        )
                                                    }
                                                >
                                                    Remove
                                                </Button>

                                            </td>

                                        </tr>

                                    ))}

                                </tbody>

                            </Table>

                        </Card.Body>

                    </Card>

                </Col>

                <Col lg={4}>

                    <Card className="shadow-sm border-0">

                        <Card.Body>

                            <h4>
                                Order Summary
                            </h4>

                            <hr />

                            <div className="d-flex justify-content-between">

                                <span>
                                    Items
                                </span>

                                <span>
                                    {cartItems.length}
                                </span>

                            </div>

                            <div className="d-flex justify-content-between mt-2">

                                <span>
                                    Total
                                </span>

                                <span>
                                    ₹{total}
                                </span>

                            </div>

                            <Button
                                variant="success"
                                className="w-100 mt-4"
                                disabled={
                                    cartItems.length === 0
                                }
                                onClick={() =>
                                    navigate("/checkout")
                                }
                            >
                                Continue To Checkout
                            </Button>

                        </Card.Body>

                    </Card>

                </Col>

            </Row>

        </Container>
    );
}