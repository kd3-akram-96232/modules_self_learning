import { useEffect, useState } from "react";
import axios from "axios";
import { toast } from "react-toastify";
import FoodCard from "./FoodCard";
import { Constaint } from "../utils/Constaint";

export default function FoodGrid() {

    const [foods, setFoods] = useState([]);
    const [loading, setLoading] = useState(true);

    const getFoods = async () => {
        try {

            const response = await axios.get(
                Constaint.BASE_URL + "/api/food"
            );

            const { status, error, data } =
                response.data;

            if (!status) {
                return toast.error(error);
            }

            setFoods(data);

        } catch (err) {

            toast.error("Failed to load foods");

        } finally {

            setLoading(false);

        }
    };

    useEffect(() => {
        getFoods();
    }, []);

    if (loading) {
        return (
            <div className="text-center py-5">
                Loading foods...
            </div>
        );
    }

    return (
        <div className="row g-4">
            {
                foods.map(food => (
                    <div
                        className="col-lg-3 col-md-4 col-sm-6"
                        key={food.fid}
                    >
                        <FoodCard food={food} />
                    </div>
                ))
            }
        </div>
    );
}