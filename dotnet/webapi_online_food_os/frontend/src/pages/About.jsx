import { Container, Row, Col, Card } from "react-bootstrap";

export default function AboutPage() {
    return (
        <>
            {/* Hero Section */}
            <section className="bg-danger text-white py-5">
                <Container className="text-center">
                    <h1 className="display-4 fw-bold">
                        About FoodOn
                    </h1>

                    <p className="lead mt-3">
                        Delivering happiness, one meal at a time.
                    </p>
                </Container>
            </section>

            {/* Story Section */}
            <section className="py-5">
                <Container>
                    <Row className="align-items-center">
                        <Col md={6}>
                            <img
                                src="https://images.unsplash.com/photo-1517248135467-4c7edcad34c4"
                                alt="Restaurant"
                                className="img-fluid rounded shadow"
                            />
                        </Col>

                        <Col md={6}>
                            <h2 className="fw-bold mb-4">
                                Our Story
                            </h2>

                            <p className="text-muted">
                                FoodOn was created with a simple mission:
                                make food ordering fast, convenient, and
                                enjoyable for everyone.
                            </p>

                            <p className="text-muted">
                                We connect customers with their favorite
                                restaurants and deliver fresh meals right
                                to their doorstep with speed and reliability.
                            </p>
                        </Col>
                    </Row>
                </Container>
            </section>

            {/* Features */}
            <section className="bg-light py-5">
                <Container>
                    <h2 className="text-center fw-bold mb-5">
                        Why Choose Us
                    </h2>

                    <Row className="g-4">

                        <Col md={4}>
                            <Card className="h-100 border-0 shadow-sm text-center p-4">
                                <h1>⚡</h1>
                                <h4>Fast Delivery</h4>
                                <p className="text-muted">
                                    Hot and fresh meals delivered quickly.
                                </p>
                            </Card>
                        </Col>

                        <Col md={4}>
                            <Card className="h-100 border-0 shadow-sm text-center p-4">
                                <h1>🍔</h1>
                                <h4>Quality Food</h4>
                                <p className="text-muted">
                                    Carefully selected restaurants and dishes.
                                </p>
                            </Card>
                        </Col>

                        <Col md={4}>
                            <Card className="h-100 border-0 shadow-sm text-center p-4">
                                <h1>💳</h1>
                                <h4>Secure Payments</h4>
                                <p className="text-muted">
                                    Multiple safe and secure payment methods.
                                </p>
                            </Card>
                        </Col>

                    </Row>
                </Container>
            </section>

            {/* Stats */}
            <section className="py-5">
                <Container>
                    <Row className="text-center">

                        <Col md={3}>
                            <h2 className="fw-bold text-danger">10K+</h2>
                            <p>Happy Customers</p>
                        </Col>

                        <Col md={3}>
                            <h2 className="fw-bold text-danger">500+</h2>
                            <p>Restaurants</p>
                        </Col>

                        <Col md={3}>
                            <h2 className="fw-bold text-danger">50K+</h2>
                            <p>Orders Delivered</p>
                        </Col>

                        <Col md={3}>
                            <h2 className="fw-bold text-danger">24/7</h2>
                            <p>Customer Support</p>
                        </Col>

                    </Row>
                </Container>
            </section>
        </>
    );
}