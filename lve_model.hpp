#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <vector>
#include <memory>
#include <glm/glm.hpp>

#include "lve_device.hpp"
#include "lve_buffer.hpp"

namespace lve {
    class LveModel
    {
    public:
        struct Vertex {
            glm::vec3 position{};
            glm::vec3 color{};
            glm::vec3 normal{};
            glm::vec2 uv{};

            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
            bool operator==(const Vertex &other) const {
                return position == other.position && color == other.color && normal == other.normal && uv == other.uv;
            }
        };

        struct Builder {
            std::vector<Vertex> vertices{};
            std::vector<uint32_t> indices{};

            void loadModel(const std::string& filepath);
        };

        LveModel(LveDevice &device, const LveModel::Builder &builder);
        ~LveModel();

        LveModel(const LveModel&) = delete;
        LveModel &operator=(const LveModel&) = delete;

        static std::unique_ptr<LveModel> createModelFromFile(LveDevice &device, const std::string &filepath);

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);

    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);
        void createIndexBuffers(const std::vector<uint32_t> &indices);

        
        LveDevice &lveDevice;
        uint32_t vertexCount;
        std::unique_ptr<LveBuffer> vertexBuffer;

        bool hasIndexBuffer = false;
        uint32_t indexCount;
        std::unique_ptr<LveBuffer> indexBuffer;

    };
}