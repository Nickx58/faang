import Todo from "./components/Todo/Todo";
import Pagination from "./components/Pagination/Pagination";
import Tabs from "./components/Tab";
import Accordion from "./components/Accordion/Accordion";
import Chips from "./components/Chips/Chips";
import Quiz from "./components/Quiz/Quiz";

function App() {
  return (
    <>
      <Tabs defaultValue="tab1">
        <Tabs.List>
          <Tabs.Trigger value="tab1">Todo</Tabs.Trigger>
          <Tabs.Trigger value="tab2">Pagination</Tabs.Trigger>
          <Tabs.Trigger value="tab3">Accordion</Tabs.Trigger>
          <Tabs.Trigger value="tab4">Chips</Tabs.Trigger>
          <Tabs.Trigger value="tab5">Quiz</Tabs.Trigger>
        </Tabs.List>
        <Tabs.Content value="tab1">
          <Todo />
        </Tabs.Content>
        <Tabs.Content value="tab2">
          <Pagination />
        </Tabs.Content>
        <Tabs.Content value="tab3">
          <Accordion />
        </Tabs.Content>
        <Tabs.Content value="tab4">
          <Chips />
        </Tabs.Content>
        <Tabs.Content value="tab5">
          <Quiz />
        </Tabs.Content>
      </Tabs>
    </>
  );
}

export default App;
