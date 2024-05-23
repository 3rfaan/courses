import { useEffect, useState } from "react";
import { useAuthContext } from "../context/AuthContext";
import RepositoryDetails from "./RepositoryDetails";
import MasterDetail from "../MasterDetail";
import { Col, message } from "antd";
import { Nullable, Repository } from "../../types";
import { invoke } from "@tauri-apps/api/tauri";
import { getErrorMessage } from "../../helper";

const PrivateRepositories: React.FC = () => {
    const { token } = useAuthContext();
    const [repositories, setRepositories] = useState<Repository[]>([]);
    const [messageApi, contextHolder] = message.useMessage();

    useEffect(() => {
        const getRepositories = async () => {
            if (token) {
                try {
                    const repositories: Repository[] = await invoke(
                        "get_repositories_for_authenticated_user",
                        { token }
                    );
                    setRepositories(repositories);
                } catch (error) {
                    messageApi.open({
                        type: "error",
                        content: getErrorMessage(error),
                    });
                }
            }
        };
        getRepositories();
    }, [token]);

    const title = "Private Repositories";
    const getItemDescription = (repository: Repository) => repository.name;
    const detailLayout = (repository: Nullable<Repository>) => {
        if (!repository) return null;
        return (
            <Col span={18}><RepositoryDetails repository={repository} token={token} /></Col>
        );
    };

    return (
        <>
            {contextHolder}
            <MasterDetail
                title={title}
                items={repositories}
                getItemDescription={getItemDescription}
                detailLayout={detailLayout}
            />
        </>
    );
};

export default PrivateRepositories;
