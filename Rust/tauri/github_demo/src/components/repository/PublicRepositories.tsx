import { useEffect, useState } from "react";
import { Col, message } from "antd";
import { Nullable, Repository } from "../../types";
import RepositoryDetails from "./RepositoryDetails";
import MasterDetail from "../MasterDetail";
import { invoke } from "@tauri-apps/api/tauri";
import { getErrorMessage } from "../../helper";

const PublicRepositories: React.FC = () => {
    const [repositories, setRepositories] = useState<Repository[]>([]);
    const [messageApi, contextHolder] = message.useMessage();

    useEffect(() => {
        const getRepositories = async () => {
            try {
                const repositories: Repository[] = await invoke(
                    "get_public_repositories"
                );
                setRepositories(repositories);
            } catch (error) {
                messageApi.open({
                    type: "error",
                    content: getErrorMessage(error),
                });
            }
        };
        getRepositories();
    }, []);

    const title = "Public Repositories";
    const getItemDescription = (repository: Repository) => repository.name;
    const detailLayout = (repository: Nullable<Repository>) => {
        if (!repository) return null;
        return (
            <Col span={18}><RepositoryDetails repository={repository} /></Col>
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

export default PublicRepositories;
