import { useState } from "react";
import {
    Container,
    Card,
    Form,
    Button,
    Row,
    Col,
    Image
} from "react-bootstrap";
import axios from "axios";
import { toast } from "react-toastify";
import { Constaint } from "../utils/Constaint";

export default function CreateFoodPage() {

    const [loading, setLoading] = useState(false);

    const [form, setForm] = useState({
        Name: "",
        Description: "",
        Price: ""
    });

    const [image, setImage] = useState(null);
    const [preview, setPreview] = useState(null);

    const handleChange = (e) => {

        setForm({
            ...form,
            [e.target.name]: e.target.value
        });

    };

    const handleImage = (e) => {

        const file = e.target.files[0];

        setImage(file);

        if (file) {
            setPreview(
                URL.createObjectURL(file)
            );
        }
    };

    const createFood = async (e) => {

        e.preventDefault();

        try {

            setLoading(true);

            const formData = new FormData();

            formData.append(
                "Name",
                form.Name
            );

            formData.append(
                "Description",
                form.Description
            );

            formData.append(
                "Price",
                form.Price
            );

            formData.append(
                "Image",
                image
            );

            const response =
                await axios.post(
                    `${Constaint.BASE_URL}/api/Food`,
                    formData,
                    { withCredentials: true }
                );

            const {
                status,
                error
            } = response.data;

            if (!status) {
                return toast.error(error);
            }

            toast.success(
                "Food created successfully"
            );

            setForm({
                Name: "",
                Description: "",
                Price: ""
            });

            setImage(null);
            setPreview(null);

            navigation('/admin-foods');

        } catch (err) {

            toast.error(
                err.response?.data?.error ||
                "Failed to create food"
            );

        } finally {

            setLoading(false);

        }
    };

    return (
        <Container className="py-4">

            <Card className="border-0 shadow-sm">

                <Card.Body>

                    <h2 className="mb-4">
                        Create Food
                    </h2>

                    <Form onSubmit={createFood}>

                        <Row>

                            <Col md={6}>

                                <Form.Group className="mb-3">

                                    <Form.Label>
                                        Food Name
                                    </Form.Label>

                                    <Form.Control
                                        name="Name"
                                        value={form.Name}
                                        onChange={handleChange}
                                    />

                                </Form.Group>

                            </Col>

                            <Col md={6}>

                                <Form.Group className="mb-3">

                                    <Form.Label>
                                        Price
                                    </Form.Label>

                                    <Form.Control
                                        type="number"
                                        step="0.01"
                                        name="Price"
                                        value={form.Price}
                                        onChange={handleChange}
                                    />

                                </Form.Group>

                            </Col>

                        </Row>

                        <Form.Group className="mb-3">

                            <Form.Label>
                                Description
                            </Form.Label>

                            <Form.Control
                                as="textarea"
                                rows={4}
                                name="Description"
                                value={form.Description}
                                onChange={handleChange}
                            />

                        </Form.Group>

                        <Form.Group className="mb-3">

                            <Form.Label>
                                Food Image
                            </Form.Label>

                            <Form.Control
                                type="file"
                                accept="image/*"
                                onChange={handleImage}
                            />

                        </Form.Group>

                        {preview && (

                            <Image
                                src={preview}
                                rounded
                                width={200}
                                className="mb-3"
                            />

                        )}

                        <Button
                            type="submit"
                            variant="success"
                            disabled={loading}
                        >
                            {
                                loading
                                    ? "Creating..."
                                    : "Create Food"
                            }
                        </Button>

                    </Form>

                </Card.Body>

            </Card>

        </Container>
    );
}