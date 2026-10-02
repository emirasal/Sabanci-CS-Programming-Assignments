import React, { useState, useEffect } from "react";
import { Link } from "react-router-dom";
import "./Navbar.css";
import Cart from "./Cart";

function Navbar() {
    const [accessToken, setAccessToken] = useState(true);

    const logout = () => {
        setAccessToken(null);
        localStorage.removeItem("token")
        localStorage.removeItem("userId")
        window.location.reload()
    };

    useEffect(() => {
        setAccessToken(localStorage.getItem("token"));
    }, [accessToken]);

    return (
        <nav className="navbar">

                <Link to="/" className="navbar-logo">
                    Index <i className="fa-solid fa-desktop" />
                </Link>
                                                                                                                                                                                              
                <Link
                    to={Cart}>
                    <Cart />
                </Link>

                <Link class="navbar-items" onClick={logout}>
                    <h5>Logout</h5>
                </Link>
        </nav>
    );
}

export default Navbar;