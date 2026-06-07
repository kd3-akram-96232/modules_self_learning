import { Card, Button, Badge } from "react-bootstrap";
import { Constaint } from "../utils/Constaint";
import { useDispatch } from "react-redux";
import { incrementQuantity } from "../redux/reducers/CartSlice";
import { toast } from "react-toastify";

export default function FoodCard({ food }) {

    const dispatch = useDispatch();

    const addToCart = () => {

        dispatch(incrementQuantity(food));

        toast.success(
            `${food.name} added to cart`
        );
    };

    const foodImage =
        Constaint.BASE_URL +
        "/FoodImages/" +
        food.image;

    return (
        <Card className="border-0 shadow-sm h-100 food-card">

            <div className="position-relative">

                <Card.Img
                    src={foodImage}
                    style={{
                        height: "220px",
                        objectFit: "cover"
                    }}
                />

                <Badge
                    bg="danger"
                    className="position-absolute top-0 end-0 m-2"
                >
                    ₹{food.price}
                </Badge>

            </div>

            <Card.Body className="d-flex flex-column">

                <Card.Title>
                    {food.name}
                </Card.Title>

                <Card.Text
                    className="text-muted flex-grow-1"
                    style={{
                        overflow: "hidden",
                        display: "-webkit-box",
                        WebkitLineClamp: 2,
                        WebkitBoxOrient: "vertical"
                    }}
                >
                    {food.description}
                </Card.Text>

                <Button
                    variant="danger"
                    className="w-100 mt-auto"
                    onClick={addToCart}
                >
                    Add To Cart
                </Button>

            </Card.Body>

        </Card>
    );
}