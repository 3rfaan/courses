import { GithubUser } from "../../types";
import { Avatar, Card, List } from "antd";

interface Props {
    users: GithubUser[];
}

const UserGrid: React.FC<Props> = ({ users }) => (
    <List
        grid={{ gutter: 16, column: 4 }}
        dataSource={users}
        renderItem={(user, index) => (
            <List.Item key={index} style={{ marginTop: "5px" }}>
                <Card.Meta
                    avatar={<Avatar src={user.avatar_url} />}
                    title={user.login}
                />
            </List.Item>
        )}
    />
);

export default UserGrid;
