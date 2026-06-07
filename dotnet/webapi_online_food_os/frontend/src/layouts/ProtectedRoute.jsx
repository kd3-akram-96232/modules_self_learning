import { useSelector } from "react-redux";
import { Link, Outlet, useNavigate } from "react-router-dom";
import { toast } from "react-toastify";

export default function ProtectedLayout(){
    const navigate = useNavigate();

    const user = useSelector(state => state.User.user);

    if(!user){
        return (
            <div className="d-flex align-items-center p-3">
                you are not a logged in user please login first.
                <Link to="/login"> Go to login page</Link>
            </div>
        )
    }

    return(
        <main>
            <Outlet/>
        </main>
    )
}