import React, { useState, useMemo } from "react";
import countryList from 'react-select-country-list'

function AdressInfo({ formData, setFormData }) {

  const [value, setValue] = useState("")
  const options = useMemo(() => countryList().getData(), [])

  const changeHandler = value => {
    setValue(value)
    setFormData({ ...formData, country: value });
  }
   
  return (
    <div className="other-info-container">
      <select value={value} onChange={(e) => changeHandler(e.target.value)}>
        {options.map((option) => (
          <option key={option.value} value={option.value}>
            {option.label}
          </option>
        ))}
      </select>
      <input className="paymentFormInput"
        type="text"
        placeholder="State"
        value={formData.state}
        onChange={(e) => {
          setFormData({ ...formData, state: e.target.value });
        }}
      />
      <input className="paymentFormInput"
        type="text"
        placeholder="City"
        value={formData.city}
        onChange={(e) => {
          setFormData({ ...formData, city: e.target.value });
        }}
      />
      <input className="paymentFormInput"
        type="text"
        placeholder="Zip-code"
        value={formData.postalCode}
        onChange={(e) => {
          setFormData({ ...formData, postalCode: e.target.value });
        }}
      />
      <input className="paymentFormInput"
        type="text"
        placeholder="Address Details"
        value={formData.addressLine1}
        onChange={(e) => {
          setFormData({ ...formData, addressLine1: e.target.value });
        }}
      />

    </div>
  );
}

export default AdressInfo;