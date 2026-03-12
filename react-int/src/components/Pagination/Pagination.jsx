import useFetch from "../../hooks/useFetch";

function Pagination() {
  const {
    data = [],
    isLoading,
    error,
  } = useFetch("https://jsonplaceholder.typicode.com/posts");

  if (isLoading) {
    return <div>Loading....</div>;
  }
  if (error) {
    return <p>Something went wrong</p>;
  }

  return (
    <div>
      {data?.map((post) => {
        return <p key={post.id}>{post.title}</p>;
      })}
    </div>
  );
}

export default Pagination;
