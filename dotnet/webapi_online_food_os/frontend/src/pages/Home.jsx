import FoodGrid from "../components/FoodGrid";

export default function HomePage() {
    return (
        <>
            {/* Hero Section */}
            <section className="bg-danger text-white py-5">
                <div className="container text-center">
                    <h1 className="display-4 fw-bold">
                        Delicious Food Delivered To Your Door
                    </h1>

                    <p className="lead mt-3">
                        Order from your favorite restaurants in minutes.
                    </p>

                    <button className="btn btn-light btn-lg mt-3">
                        Order Now
                    </button>
                </div>
            </section>

            {/* Categories */}
            <section className="container py-5">
                <h2 className="fw-bold mb-4">
                    Popular Categories
                </h2>

                <div className="row g-4">
                    <div className="col-md-3">
                        <div className="category-card">
                            🍔 Burgers
                        </div>
                    </div>

                    <div className="col-md-3">
                        <div className="category-card">
                            🍕 Pizza
                        </div>
                    </div>

                    <div className="col-md-3">
                        <div className="category-card">
                            🍗 Chicken
                        </div>
                    </div>

                    <div className="col-md-3">
                        <div className="category-card">
                            🍨 Desserts
                        </div>
                    </div>
                </div>
            </section>

            {/* Food List */}
            <section className="container pb-5">
                <div className="d-flex justify-content-between align-items-center mb-4">
                    <h2 className="fw-bold">
                        Popular Foods
                    </h2>
                </div>

                <FoodGrid />
            </section>
        </>
    );
}