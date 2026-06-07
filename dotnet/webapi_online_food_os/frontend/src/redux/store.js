import { configureStore, createStore } from "@reduxjs/toolkit";
import { useStore } from "react-redux";
import UserSlice from "./reducers/UserSlice";
import CartSlice from "./reducers/CartSlice";

export const store = configureStore({
    reducer: {
        User: UserSlice,
        Cart: CartSlice
    }
});