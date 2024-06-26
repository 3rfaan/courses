import NavBar from "./components/NavBar";
import { FloatButton, Layout } from "antd";
import { Outlet } from "react-router-dom";

const { Content } = Layout;

const App = () => {
    return (
        <Layout
            style={{ minHeight: "100vh" }}
        >
            <NavBar />
            <Layout className="site-layout">
                <Content
                    style={{ background: "white" }}
                >
                    <Outlet />
                    <FloatButton.BackTop />
                </Content>
            </Layout>
        </Layout>
    );
};

export default App;
