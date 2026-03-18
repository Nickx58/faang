function Profile({ data, setData }) {
  const { name, age, email } = data;
  const handleValueChange = (e, input) => {
    setData((prev) => {
      return {
        ...prev,
        [input]: e.target.value,
      };
    });
  };
  return (
    <div>
      <div>
        <label>Name</label>
        <input
          type="text"
          value={name}
          onChange={(e) => handleValueChange(e, "name")}
        />
      </div>
      <div>
        <label>Age</label>
        <input
          type="text"
          value={age}
          onChange={(e) => handleValueChange(e, "age")}
        />
      </div>
      <div>
        <label>Email</label>
        <input
          type="text"
          value={email}
          onChange={(e) => handleValueChange(e, "email")}
        />
      </div>
    </div>
  );
}

export default Profile;
