import { useEffect, useState } from "react";
import {
    Container,
    Card,
    Row,
    Col,
    Badge,
    Spinner,
    Image
} from "react-bootstrap";
import { toast } from "react-toastify";
import api from "../utils/api";
import { Constaint } from "../utils/Constaint";

export default function OrdersPage() {

    const [orders, setOrders] = useState([]);
    const [loading, setLoading] = useState(true);

    const getOrders = async () => {

        try {

            const response = await api.get(Constaint.BASE_URL + '/api/orders', { withCredentials: true });

            const {
                status,
                data,
                error
            } = response.data;

            if (!status) {
                return toast.error(error);
            }

            setOrders(data);

        } catch (err) {

            toast.error(
                err.response?.data?.error ||
                "Failed to load orders"
            );

        } finally {

            setLoading(false);

        }
    };

    useEffect(() => {
        getOrders();
    }, []);

    if (loading) {
        return (
            <Container className="py-5 text-center">
                <Spinner animation="border" />
            </Container>
        );
    }

    return (
        <>
            {/* Hero Section */}
            <section className="bg-danger text-white py-5">
                <Container>
                    <h1 className="fw-bold">
                        📦 My Orders
                    </h1>

                    <p className="mb-0">
                        View all your previous orders
                    </p>
                </Container>
            </section>

            <Container className="py-5">

                {orders.length === 0 && (
                    <Card className="border-0 shadow-sm text-center p-5">
                        <h3>No Orders Found</h3>
                        <p className="text-muted">
                            Start ordering delicious food.
                        </p>
                    </Card>
                )}

                {orders.map(order => (

                    <Card
                        key={order.oid}
                        className="border-0 shadow-sm mb-4"
                    >
                        <Card.Body>

                            {/* Header */}
                            <Row className="align-items-center">

                                <Col md={8}>
                                    <h5 className="fw-bold mb-1">
                                        Order #{order.oid}
                                    </h5>

                                    <small className="text-muted">
                                        Ordered On :
                                        {" "}
                                        {new Date(
                                            order.odate
                                        ).toLocaleString()}
                                    </small>
                                </Col>

                                <Col
                                    md={4}
                                    className="text-md-end mt-3 mt-md-0"
                                >
                                    <Badge
                                        bg={
                                            order.deldate
                                                ? "success"
                                                : "warning"
                                        }
                                        className="px-3 py-2"
                                    >
                                        {
                                            order.deldate
                                                ? "Delivered"
                                                : "Pending"
                                        }
                                    </Badge>

                                    <h4 className="mt-2 text-danger">
                                        ₹{order.totalAmount}
                                    </h4>
                                </Col>

                            </Row>

                            <hr />

                            {/* Items */}
                            {order.orderDetails.length === 0 ? (

                                <div className="text-center text-muted py-3">
                                    No items available.
                                </div>

                            ) : (

                                order.orderDetails.map(
                                    (item, index) => {

                                        const imageUrl =
                                            item.food.image
                                                ? `${Constaint.BASE_URL}/FoodImages/${item.food.image}`
                                                : "https://placehold.co/100x100";

                                        return (
                                            <div
                                                key={index}
                                                className="d-flex justify-content-between align-items-center mb-3"
                                            >

                                                <div className="d-flex gap-3">

                                                    <Image
                                                        src={imageUrl}
                                                        rounded
                                                        width={80}
                                                        height={80}
                                                        style={{
                                                            objectFit: "cover"
                                                        }}
                                                    />

                                                    <div>

                                                        <h6 className="mb-1">
                                                            {item.food.name}
                                                        </h6>

                                                        <p
                                                            className="text-muted mb-1"
                                                            style={{
                                                                fontSize: "14px"
                                                            }}
                                                        >
                                                            {
                                                                item.food.description
                                                            }
                                                        </p>

                                                        <small>
                                                            Qty :
                                                            {" "}
                                                            <strong>
                                                                {
                                                                    item.quantity
                                                                }
                                                            </strong>
                                                        </small>

                                                    </div>

                                                </div>

                                                <div className="text-end">

                                                    <h6 className="mb-0">
                                                        ₹
                                                        {
                                                            item.food.price
                                                        }
                                                    </h6>

                                                    <small className="text-muted">
                                                        Total :
                                                        {" "}
                                                        ₹
                                                        {
                                                            item.food.price *
                                                            item.quantity
                                                        }
                                                    </small>

                                                </div>

                                            </div>
                                        );
                                    }
                                )

                            )}

                        </Card.Body>
                    </Card>

                ))}

            </Container>
        </>
    );
}