import { Outlet } from "react-router-dom";
import Navbar from "../components/Navbar";

export default function AuthLayout(){
    return(
        <main>
            <Navbar/>
            <Outlet/>
        </main>
    )
}