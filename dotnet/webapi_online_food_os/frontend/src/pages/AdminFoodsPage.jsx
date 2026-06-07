import { useEffect, useState } from "react";
import {
    Container,
    Card,
    Button,
    Row,
    Col
} from "react-bootstrap";
import axios from "axios";
import { toast } from "react-toastify";
import { Constaint } from "../utils/Constaint";
import { Link } from "react-router-dom";

export default function AdminFoodsPage() {

    const [foods, setFoods] = useState([]);

    const getFoods = async () => {

        try {

            const response =
                await axios.get(
                    `${Constaint.BASE_URL}/api/Food`
                );

            const {
                status,
                data
            } = response.data;

            if (status) {
                setFoods(data);
            }

        } catch {

            toast.error(
                "Failed to load foods"
            );

        }
    };

    const deleteFood = async (fid) => {

        if (
            !window.confirm(
                "Delete this food?"
            )
        ) {
            return;
        }

        try {

            await axios.delete(
                `${Constaint.BASE_URL}/api/Food/${fid}`,
                { withCredentials: true }
            );

            toast.success(
                "Food deleted"
            );

            getFoods();

        } catch {

            toast.error(
                "Delete failed"
            );

        }
    };

    useEffect(() => {
        getFoods();
    }, []);

    return (
        <Container className="py-4">

            <div className="d-flex justify-content-between align-items-center mb-4">

                <h2>
                    Manage Foods
                </h2>

                <Link to={'/create-food'}>
                    <Button>+ Add food</Button>
                </Link>

            </div>

            <Row>

                {foods.map(food => {

                    const image =
                        food.image
                            ? `${Constaint.BASE_URL}/FoodImages/${food.image}`
                            : "https://placehold.co/300x200";

                    return (

                        <Col
                            lg={4}
                            md={6}
                            key={food.fid}
                            className="mb-4"
                        >

                            <Card className="h-100 shadow-sm">

                                <Card.Img
                                    variant="top"
                                    src={image}
                                    style={{
                                        height: "220px",
                                        objectFit: "cover"
                                    }}
                                />

                                <Card.Body>

                                    <h5>
                                        {food.name}
                                    </h5>

                                    <p className="text-muted">
                                        {
                                            food.description
                                        }
                                    </p>

                                    <h6 className="text-success">
                                        ₹{food.price}
                                    </h6>

                                    <Button
                                        variant="danger"
                                        className="w-100 mt-2"
                                        onClick={() =>
                                            deleteFood(
                                                food.fid
                                            )
                                        }
                                    >
                                        Delete Food
                                    </Button>

                                </Card.Body>

                            </Card>

                        </Col>

                    );
                })}

            </Row>

        </Container>
    );
}