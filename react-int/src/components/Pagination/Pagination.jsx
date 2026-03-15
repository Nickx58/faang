import { useState } from "react";
import useFetch from "../../hooks/useFetch/useFetch";

const URL = "https://dummyjson.com/users";

function Pagination() {
  const limit = 10;
  const [page, setPage] = useState(1);
  const skip = (page - 1) * limit;

  const {
    data = {},
    isLoading,
    error,
  } = useFetch(`${URL}?limit=${limit}&skip=${skip}`);

  if (isLoading) {
    return <div>Loading....</div>;
  }
  if (error) {
    return <p>Something went wrong</p>;
  }

  const totalPages = Math.ceil(data?.total / limit);

  return (
    <div>
      <h2>User List</h2>

      <ul>
        {data?.users.map((user) => (
          <li key={user.id}>
            {user.firstName} {user.lastName}
          </li>
        ))}
      </ul>

      <div style={{ marginTop: "20px" }}>
        <button
          disabled={page === 1}
          onClick={() => setPage((prev) => prev - 1)}
        >
          Prev
        </button>

        <span style={{ margin: "0 10px" }}>
          Page {page} of {totalPages}
        </span>

        <button
          disabled={page === totalPages}
          onClick={() => setPage((prev) => prev + 1)}
        >
          Next
        </button>
      </div>
    </div>
  );
}

export default Pagination;
