import React, { useState } from "react";
import PaymentInfo from "./PaymentInfo";
import AddressInfo from "./AddressInfo";
import "./Form.css"
import {useNavigate} from "react-router-dom";

function Form({cartData}) {
  const [page, setPage] = useState(0);
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    addressLine1: "",
    addressLine2: "",
    city: "",
    state: "",
    postalCode: "",
    country: "",
    phoneNumber: "",
    cardNum: "",
    expiry: "",
    cvc: "",

  });

  const FormTitles = ["Payment Info", "Address"];

  const PageDisplay = () => {
    if (page === 0) {
      return <PaymentInfo formData={formData} setFormData={setFormData} />;
    } 
    else {
      return <AddressInfo formData={formData} setFormData={setFormData} />;
    }
  };

  return (
    <div className="form">
      <div className="form-container">
        <div className="header">
          <h1>{FormTitles[page]}</h1>
        </div>
        <div className="body">{PageDisplay()}</div>
        <div className="checkout-button">
          
          <button
            onClick={() => {
              if (page === FormTitles.length - 1) {
                for (let i = 0; i < cartData.products.length; i++) {
                  const product = cartData.products[i];
                  const productId = product.productId;
                  const quantity = product.quantity;
                  fetch(`http://localhost:8080/api/products/decreaseStock/${productId}/${quantity}`, {
                    method: "GET",
                  })
                    .catch((error) => {
                      console.error(error);
                    });
                }
              
                window.alert("Successful Order");
                navigate("/");
              }
                setPage((currPage) => currPage + 1);
  
            }}
          >
            {page === FormTitles.length - 1 ? "Submit Order" : "Next"}
          </button>
        </div>
      </div>
    </div>
  );
}

export default Form