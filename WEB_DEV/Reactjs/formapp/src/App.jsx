import React, { useState } from 'react';

function App() {
  const [formData, setFormData] = useState({
    name: '',
    phoneNumber: '',
    email: '',
    password: ''
  });

  const [errors, setErrors] = useState({});
  const [formSubmitted, setFormSubmitted] = useState(false);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData({
      ...formData,
      [name]: value
    });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const errors = validateForm(formData);
    if (Object.keys(errors).length === 0) {
      setFormSubmitted(true);
      console.log('Form submitted successfully!');
    } else {
      setErrors(errors);
    }
  };

  const validateForm = (data) => {
    let errors = {};

    if (!data.name.trim()) {
      errors.name = 'Name is required';
    }

    if (!/^\d{10}$/.test(data.phoneNumber.trim())) {
      errors.phoneNumber = 'Phone number must be 10 digits';
    }

    if (!/^\S+@\S+\.\S+$/.test(data.email.trim())) {
      errors.email = 'Email is invalid';
    }

    if (data.password.length < 6) {
      errors.password = 'Password must be at least 6 characters';
    }

    return errors;
  };

  return (
    <div>
      <h1>Form with Validation</h1>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Name:</label>
          <input type="text" name="name" value={formData.name} onChange={handleChange} />
          {errors.name && <span>{errors.name}</span>}
        </div>
        <div>
          <label>Phone Number:</label>
          <input type="text" name="phoneNumber" value={formData.phoneNumber} onChange={handleChange} />
          {errors.phoneNumber && <span>{errors.phoneNumber}</span>}
        </div>
        <div>
          <label>Email:</label>
          <input type="email" name="email" value={formData.email} onChange={handleChange} />
          {errors.email && <span>{errors.email}</span>}
        </div>
        <div>
          <label>Password:</label>
          <input type="password" name="password" value={formData.password} onChange={handleChange} />
          {errors.password && <span>{errors.password}</span>}
        </div>
        <button type="submit">Submit</button>
      </form>
      {formSubmitted && <p>Form submitted successfully!</p>}
    </div>
  );
}

export default App;
